import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Van Hanh Pham <skyvn97> <vanhanh.pham@gmail.com>
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final String YES = "Yes";
        private static final String NO = "No";
        private InputReader in;
        private PrintWriter out;
        private TaskD.Edge[] edges;
        private TaskD.Node[] nodes;
        private int numNode;
        private int numEdge;
        private int numImportant;
        private int numVariable;
        private ArrayList<Pair<TaskD.Edge, TaskD.Edge>> mustRemove;

        private void noAnswer() {
            out.println(NO);
            throw new TaskD.NoAnswerException();
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            try {
                loadGraph();
                prepare();
                process();
            } catch (TaskD.NoAnswerException exception) {
            }
        }

        private void loadGraph() {
            numNode = in.nextInt();
            nodes = new TaskD.Node[numNode + 1];
            for (int i = 1; i <= numNode; i++) nodes[i] = new TaskD.Node();
            numEdge = in.nextInt();
            edges = new TaskD.Edge[numEdge];
            for (int i = 0; i < numEdge; i++) {
                edges[i] = new TaskD.Edge(in, i);
                nodes[edges[i].u].adj.add(edges[i]);
                nodes[edges[i].v].adj.add(edges[i]);
            }
        }

        private void prepare() {
            mustRemove = new ArrayList<Pair<TaskD.Edge, TaskD.Edge>>();
            for (int i = 1; i <= numNode; i++) {
                Pair<TaskD.Edge, TaskD.Edge> pair = getImportantEdge(nodes[i]);
                if (pair == null) continue;
                mustRemove.add(pair);
                if (pair.first.importantIndex < 0) pair.first.importantIndex = numImportant++;
                if (pair.second.importantIndex < 0) pair.second.importantIndex = numImportant++;
            }

            for (TaskD.Edge e : edges)
                if (e.importantIndex >= 0) {
                    nodes[e.u].importantAdj.add(e);
                    nodes[e.v].importantAdj.add(e);
                }

            numVariable = numImportant;
            for (int i = 1; i <= numNode; i++) {
                TaskD.Node cur = nodes[i];
                if (cur.importantAdj.size() < 2) continue;
                for (int j = 0; j < cur.importantAdj.size() - 1; j++)
                    cur.tmpVar.add(numVariable++);
            }
        }

        private Pair<TaskD.Edge, TaskD.Edge> getImportantEdge(TaskD.Node node) {
            TreeMap<Integer, ArrayList<TaskD.Edge>> haveColor = new TreeMap<Integer, ArrayList<TaskD.Edge>>();
            Pair<TaskD.Edge, TaskD.Edge> res = null;

            for (TaskD.Edge e : node.adj) {
                if (!haveColor.containsKey(e.color)) haveColor.put(e.color, new ArrayList<TaskD.Edge>());
                ArrayList<TaskD.Edge> cur = haveColor.get(e.color);
                cur.add(e);
                if (cur.size() > 2) noAnswer();
                if (cur.size() == 2) {
                    if (res != null) noAnswer();
                    res = new Pair<TaskD.Edge, TaskD.Edge>(cur.get(0), cur.get(1));
                }
            }
            return res;
        }

        private void process() {
            int res = findResult();
            if (res >= Others.intINF) noAnswer();
            if (!ok(res, true)) throw new RuntimeException();
        }

        private int findResult() {
            int L = 0;
            int R = Others.intINF;
            while (true) {
                if (L == R) return L;
                if (R - L == 1) return ok(L, false) ? L : R;
                int M = (L + R) >> 1;
                if (ok(M, false)) R = M;
                else L = M + 1;
            }
        }

        private boolean ok(int allowTime, boolean trace) {
            TwoSat twoSat = new TwoSat(numVariable);
            for (Pair<TaskD.Edge, TaskD.Edge> pair : mustRemove)
                twoSat.addCondition(pair.first.importantIndex, TwoSat.POSITIVE,
                        pair.second.importantIndex, TwoSat.POSITIVE);
            for (TaskD.Edge e : edges)
                if (e.importantIndex >= 0 && e.time > allowTime)
                    twoSat.addMustFalseCondition(e.importantIndex);

            for (int i = 1; i <= numNode; i++)
                if (nodes[i].importantAdj.size() > 1) {
                    TaskD.Node node = nodes[i];
                    for (int j = 0; j < node.importantAdj.size() - 1; j++) {
                        int curEdgeID = node.importantAdj.get(j).importantIndex;
                        int curTmpID = node.tmpVar.get(j);
                        twoSat.addCondition(curEdgeID, TwoSat.NEGATIVE, curTmpID, TwoSat.POSITIVE);
                        if (j > 0) {
                            int prevTmpID = node.tmpVar.get(j - 1);
                            twoSat.addCondition(prevTmpID, TwoSat.NEGATIVE, curTmpID, TwoSat.POSITIVE);
                        }
                        int nextEdgeID = node.importantAdj.get(j + 1).importantIndex;
                        twoSat.addCondition(curTmpID, TwoSat.NEGATIVE, nextEdgeID, TwoSat.NEGATIVE);
                    }
                }

            boolean result = twoSat.haveSolution();
            if (!trace) return result;
            if (!result) throw new RuntimeException();

            boolean[] res = twoSat.findSolution();
            ArrayList<TaskD.Edge> toErase = new ArrayList<TaskD.Edge>();
            for (TaskD.Edge e : edges)
                if (e.importantIndex >= 0 && res[e.importantIndex])
                    toErase.add(e);

            out.printf("%s\n%d %d\n", YES, allowTime, toErase.size());
            for (TaskD.Edge e : toErase) out.printf("%d ", e.index + 1);
            out.println();
            return true;
        }

        private static class NoAnswerException extends RuntimeException {
        }

        private static class Edge {
            public int u;
            public int v;
            public int color;
            public int time;
            public int index;
            public int importantIndex;

            public Edge(InputReader in, int index) {
                u = in.nextInt();
                v = in.nextInt();
                color = in.nextInt();
                time = in.nextInt();

                this.index = index;
                importantIndex = -1;
            }

        }

        private static class Node {
            public ArrayList<TaskD.Edge> adj;
            public ArrayList<TaskD.Edge> importantAdj;
            public ArrayList<Integer> tmpVar;

            public Node() {
                adj = new ArrayList<TaskD.Edge>();
                importantAdj = new ArrayList<TaskD.Edge>();
                tmpVar = new ArrayList<Integer>();
            }

        }

    }

    static class Others {
        public static final int intINF = (int) 1e9 + 7;

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextString() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }

    static class TwoSat {
        public static final TwoSat.VariableType POSITIVE = new TwoSat.VariableType(true);
        public static final TwoSat.VariableType NEGATIVE = new TwoSat.VariableType(false);
        private int n;
        private int cnt;
        private int numComp;
        private TwoSat.Node[] nodes;
        private Stack<TwoSat.Node> stack;
        private TwoSat.Component[] components;

        public TwoSat(int n) {
            this.n = n;
            cnt = numComp = 0;
            nodes = new TwoSat.Node[2 * n];
            for (int i = 0; i < 2 * n; i++) nodes[i] = new TwoSat.Node();
            stack = new Stack<TwoSat.Node>();
        }

        private TwoSat.Node negativeNode(int x) {
            return nodes[(x + n) % (2 * n)];
        }

        public void addCondition(int var1, TwoSat.VariableType type1, int var2, TwoSat.VariableType type2) {
            int u = type1 == POSITIVE ? var1 : (var1 + n) % (2 * n);
            int v = type2 == POSITIVE ? var2 : (var2 + n) % (2 * n);

            negativeNode(u).adj.add(nodes[v]);
            negativeNode(v).adj.add(nodes[u]);
        }

        public void addMustFalseCondition(int x) {
            addCondition(x, NEGATIVE, x, NEGATIVE);
        }

        private void dfs(TwoSat.Node node) {
            node.low = node.num = ++cnt;
            stack.push(node);
            for (TwoSat.Node next : node.adj)
                if (next.compID == -1) {
                    if (next.num == 0) {
                        dfs(next);
                        node.low = Math.min(node.low, next.low);
                    } else node.low = Math.min(node.low, next.num);
                }

            if (node.low == node.num) {
                while (true) {
                    TwoSat.Node top = stack.peek();
                    stack.pop();
                    top.compID = numComp;
                    if (top == node) break;
                }
                numComp++;
            }
        }

        public boolean haveSolution() {
            for (int i = 0; i < 2 * n; i++) if (nodes[i].num == 0) dfs(nodes[i]);
            for (int i = 0; i < n; i++)
                if (nodes[i].compID == negativeNode(i).compID) return false;
            return true;
        }

        private void dfsTopo(TwoSat.Component component) {
            for (TwoSat.Component comp : component.adj)
                if (comp.topo == 0) dfsTopo(comp);
            component.topo = cnt--;
        }

        private void assignValue(TwoSat.Component component, int value) {
            if (component.value >= 0) {
                if (component.value != value) throw new RuntimeException("Conflict assigned value");
                return;
            }

            component.value = value;
            for (TwoSat.Component comp : component.negativeComp) assignValue(comp, 1 - value);

            if (value == 1) {
                for (TwoSat.Component comp : component.adj) assignValue(comp, value);
            }

        }

        public boolean[] findSolution() {
            if (!haveSolution()) return null;

            components = new TwoSat.Component[numComp];
            for (int i = 0; i < numComp; i++) components[i] = new TwoSat.Component();
            for (int i = 0; i < 2 * n; i++) {
                TwoSat.Component cur = components[nodes[i].compID];
                cur.negativeComp.add(components[negativeNode(i).compID]);
                for (TwoSat.Node node : nodes[i].adj)
                    if (components[node.compID] != cur)
                        cur.adj.add(components[node.compID]);
            }

            cnt = 2 * n;
            for (int i = 0; i < numComp; i++) if (components[i].topo == 0) dfsTopo(components[i]);

            ArrayList<TwoSat.Component> comps = new ArrayList<TwoSat.Component>();
            for (int i = 0; i < numComp; i++) comps.add(components[i]);
            Comparator<TwoSat.Component> topoCompare = new Comparator<TwoSat.Component>() {
                public int compare(TwoSat.Component c1, TwoSat.Component c2) {
                    return c1.topo - c2.topo;
                }
            };
            Collections.sort(comps, topoCompare);

            for (int i = 0; i < numComp; i++) {
                TwoSat.Component cur = comps.get(i);
                if (cur.value >= 0) continue;
                assignValue(cur, 0);
            }

            boolean[] res = new boolean[n];
            for (int i = 0; i < n; i++) res[i] = components[nodes[i].compID].value == 1;
            return res;
        }

        private static class VariableType {
            boolean info;

            public VariableType(boolean info) {
                this.info = info;
            }

        }

        private static class Node {
            public int low;
            public int num;
            public int compID;
            public ArrayList<TwoSat.Node> adj;

            public Node() {
                low = num = 0;
                compID = -1;
                adj = new ArrayList<TwoSat.Node>();
            }

        }

        private static class Component {
            public int topo;
            public int value;
            public ArrayList<TwoSat.Component> adj;
            public ArrayList<TwoSat.Component> negativeComp;

            public Component() {
                topo = 0;
                value = -1;
                adj = new ArrayList<TwoSat.Component>();
                negativeComp = new ArrayList<TwoSat.Component>();
            }

        }

    }

    static class Pair<First, Second> {
        public First first;
        public Second second;

        public Pair() {
        }

        public Pair(First first, Second second) {
            this.first = first;
            this.second = second;
        }

        public Pair(Map.Entry<First, Second> entry) {
            first = entry.getKey();
            second = entry.getValue();
        }

        public String toString() {
            return "{ " + first.toString() + " " + second.toString() + " }";
        }

    }
}
import java.util.*;

public class Main {
	static HashMap<Long, Boolean> map = new HashMap<>();
    static long getHash(long a, long b, long c) {
        return (long)(n + 1) * (long)(n + 1) * a + (long)(n + 1) * b + c;
    }
    static boolean check(int a, int b, int c) {
        long hashV = getHash(a, b, c);

        if(map.get(hashV) != null)
            return map.get(hashV);

        // b in path a -> c
        System.out.println("? " + a + " " + b + " " + c);
        System.out.flush();
        String s = sc.next();

        map.put(hashV, s.equals("Yes"));

        return map.get(hashV);
    }
    static int findHeight(int x) {
        int nodes = 0;

        int anotherNode = rand.nextInt(n) + 1;
        while(anotherNode == x)
            anotherNode = rand.nextInt(n) + 1;

        for(int i = 1; i <= n; ++i) {
            if(check(anotherNode, x, i))
                nodes++;
        }

        if(level.get(nodes) == null) 
            return level.get(n - nodes) + 1;
        else
            return level.get(nodes);
    }
    static int findDist(int a, int b) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(check(a, i, b))
                ans++;
        }
        return ans;
    }
    static void printAns(int ans) {
        System.out.println("! " + ans);
        System.out.flush();
    }
    static int findLCA(int a, int b) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 1; i <= n; ++i) {
            if(i == a || i == b)
                continue;

            if(check(a, i, b))
                list.add(i);
        }

        ArrayList<Integer> path = new ArrayList<>();
        path.add(a);

        int vis[] = new int[list.size()];
        for(int i = 0; i < list.size(); ++i) {
            int selectedInd = -1;
            for(int j = 0; j < list.size(); ++j) {
                if(vis[j] == 0) {
                    if(selectedInd == -1)
                        selectedInd = j;
                    else if(check(a, list.get(j), list.get(selectedInd)))
                        selectedInd = j;
                }
            }
            path.add(list.get(selectedInd));
            vis[selectedInd] = 1;
        }

        int rootInd = height - height1;

        return path.get(rootInd);
    }
    static int n, k;
    static HashMap<Integer, Integer> level;
    static int height, height1;
    static Random rand;
    static Scanner sc;
    public static void main(String args[]) {
        sc = new Scanner(System.in);
        rand = new Random();

        n = sc.nextInt();
        k = sc.nextInt();

        if(n == 1) {
            printAns(1);
            return;
        }

        height = 0;
        int remNodes = n * k - n + 1;
        while(remNodes != 1) {
            height++;
            remNodes /= k;
        }

        int nodes[] = new int[height + 1];
        nodes[1] = 1;
        level = new HashMap<>();
        level.put(1, 1);
        for(int i = 2; i <= height; ++i) {
            nodes[i] = k * nodes[i - 1] + 1;
            level.put(nodes[i], i);
        }

        int node1 = rand.nextInt(n) + 1;
        height1 = findHeight(node1);

        if(height1 == height) {
            printAns(node1);
            return;
        }

        HashSet<Integer> alrSet = new HashSet<>();
        alrSet.add(node1);

        int node2 = -1;

        while(true) {
            node2 = rand.nextInt(n) + 1;
            while(alrSet.contains(node2)) 
                node2 = rand.nextInt(n) + 1;

            alrSet.add(node2);
            
            int height2 = findHeight(node2);

            if(height2 == height) {
                printAns(node2);
                return;
            }

            int dist = findDist(node1, node2);

            if(height1 + height2 + dist - 2 == 2 * height - 1) 
                break;
        }

        int fans = findLCA(node1, node2);
        printAns(fans);
    }
}
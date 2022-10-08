import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    InputStreamReader inp = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(inp);
    Scanner sc = new Scanner(inp);
    
    class Peg {
        int cnt;
        int[] data = new int[30];
        
        public Peg() {
            cnt = 0;
        }
        
        public void put(int x) {
            data[cnt++] = x;
        }
        
        public int take() {
            return data[--cnt];
        }
    }
        
    // input data
    
    int[] cnt = new int[4];
    int[][] pegs = new int[4][];
    //Peg[] pegs = new Peg[4];
    
    void inputData() {
        for (int i=1; i<=3; i++) {
            pegs[i] = new int[21];
            cnt[i] = 0;
        }
        
        int n = sc.nextInt();
        for (int i=0; i < n; i++) {
            int d = sc.nextInt();
            pegs[1][cnt[1]++] = d;
        }
    }

    // intermediate
    
    int moveCnt = 0;
    int[] a = new int[2000000];
    int[] b = new int[2000000];
    
    void move(int from, int to) {
        pegs[to][cnt[to]++] = pegs[from][--cnt[from]];
        a[moveCnt] = from;
        b[moveCnt++] = to;
    }
    
    void solveWhatever(int from, int to, int maxSize) {
        int startPos = 0;
        while (pegs[from][startPos] > maxSize) startPos++;
        
        int spare = 6 - from - to;
        int nextPos = startPos + 1;
        while (nextPos < cnt[from] && pegs[from][nextPos] == pegs[from][startPos])
            nextPos++;
        int cEq = nextPos - startPos;
        if (nextPos == cnt[from]) {
            for (int i=0; i<cEq; i++)
                move(from, to);
        } else {
            int nextSize = pegs[from][nextPos];
            solveWhatever(from, spare, nextSize);
            for (int i=0; i<cEq; i++)
                move(from, to);
            solveWhatever(spare, to, nextSize);
        }       
    }

    void solveCorrect(int from, int to, int maxSize) {
        int startPos = 0;
        while (pegs[from][startPos] > maxSize) startPos++;
        
        int spare = 6 - from - to;
        int nextPos = startPos + 1;
        while (nextPos < cnt[from] && pegs[from][nextPos] == pegs[from][startPos])
            nextPos++;
        int cEq = nextPos - startPos;
        if (nextPos == cnt[from]) {
            for (int i=0; i<cEq-1; i++)
                move(from, spare);
            move(from, to);
            for (int i=0; i<cEq-1; i++)
                move(spare, to);
        } else {
            int nextSize = pegs[from][nextPos];
            if (cEq == 1) {
                solveWhatever(from, spare, nextSize);
                move(from, to);
                solveWhatever(spare, to, nextSize);
            } else {
                solveWhatever(from, to, nextSize);
                for (int i=0; i<cEq; i++)
                    move(from, spare);
                solveWhatever(to, from, nextSize);
                for (int i=0; i<cEq; i++)
                    move(spare, to);
                solveCorrect(from, to, nextSize);
            }
        }
    }
    
    void solve() {
        solveCorrect(1, 3, pegs[1][0]);
    }
    
    // output data
    
    void writeData() {
        StringBuilder sb = new StringBuilder();
        sb.append(moveCnt + "\n");
        for (int i=0; i < moveCnt; i++) {
            sb.append(a[i]);
            sb.append(" ");
            sb.append(b[i]);
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
        
    // ================================================== //
    
    void solveAlternative() {
    }
    
    // ================================================== //
    
    static void solveTask() throws Exception {
        long time = System.currentTimeMillis();
        Solution sol = new Solution();
        sol.inputData();
        sol.solve();
        sol.writeData();
        System.err.println(System.currentTimeMillis() - time);
    }
    
    static void stressTest() {
        Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            System.out.println("testing case #" + it);
            
            // generate test case into sol
            Solution sol = new Solution();

            // copy test case into sol1
            Solution sol1 = new Solution();

            // launch
            sol.solve();
            sol1.solveAlternative();
            
            // compare answers
        }
    }
    
    public static void main(String[] args) throws Exception {
        solveTask();
        // stressTest()
    }
}
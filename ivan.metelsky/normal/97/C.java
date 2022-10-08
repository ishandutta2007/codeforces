import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    InputStreamReader inp = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(inp);
    Scanner sc = new Scanner(inp);
    
    // input data
    int n;
    double[] p;
    
    void inputData() {
        n = sc.nextInt();
        p = new double[n+1];
        for (int i=0; i<=n; i++)
            p[i] = Double.parseDouble(sc.next());
    }

    // intermediate
    double res = 0.0;
    
    void solve() {
        for (int i=0; i <= n/2; i++)
            for (int j=0; j <= n; j++) if (j > n/2) {
                double x = (2 * j - n) / (double)(2 * j - 2 * i);
                res = Math.max(res, x * p[i] + (1 - x) * p[j]);
            }
    }
    
    // output data
    
    void writeData() {
        System.out.println(res);
    }
        
    // ================================================== //
    
    void solveAlternative() {
    }
    
    // ================================================== //
    
    static void solveTask() throws Exception {
        Solution sol = new Solution();
        sol.inputData();
        sol.solve();
        sol.writeData();
    }
    
    static void stressTest() {
        Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            System.out.println("testing case #" + it);
            
            Solution sol = new Solution();
            
            // generate test case
            
            Solution sol1 = new Solution();
            
            // copy test case
            
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
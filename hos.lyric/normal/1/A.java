//  Codeforces Beta Round #1
//  Problem A

import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }
    
    Scanner in = new Scanner(System.in);
    void run() {
        long a = in.nextLong(), b = in.nextLong(), c = in.nextLong();
        System.out.println(myceil(a, c) * myceil(b , c));
    }
    long myceil(long a, long b) {
        return (a + b - 1) / b;
    }
    
    void _out(Object...os) {
        System.out.println(deepToString(os));
    }
}
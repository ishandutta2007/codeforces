import java.io.*
import java.util.*
import kotlin.collections.ArrayList

import kotlin.math.*

class Reader {
    private val In: BufferedReader
    private var st: StringTokenizer? = null
    constructor(inputStream: InputStream) {
        In = BufferedReader(InputStreamReader(inputStream))
    }
    constructor(fileName: String) {
        In = BufferedReader(FileReader(fileName))
    }
    fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) st = StringTokenizer(In.readLine().trim())
        return st!!.nextToken()
    }
    fun nextLine(): String {
        st = null
        return In.readLine()
    }
    fun nextChar(): Char = next()[0]
    fun nextDouble(): Double = next().toDouble()
    fun nextInt(): Int = next().toInt()
    fun nextLong(): Long = next().toLong()
    fun close(): Unit = In.close()
}

val sc = Reader(System.`in`)
val pr = PrintWriter(System.out)

const val HAVE_TO_GET_TC = false;
var TC = 1;

var n = 0;
var m = 0;
var q = 0;
var a = Array(400005){0};

fun solve() {
    n = sc.nextInt();
    m = sc.nextInt();
    for(i in 1..n) {
        a[i] = sc.nextInt();
        a[i] += a[i-1];
    }
    q = sc.nextInt();
    while(q-- > 0) {
        var x = sc.nextInt();
        var done = 0;
        var P = 0;
        for(i in 1..x+1) {
            var T = 0;
            if(i == x+1) T = m+1;
            else T = sc.nextInt();
            var S = done;
            var E = n;
            while(S<E) {
                var M = (S+E)/2+1;
                if(a[M] - a[done] <= T - P - 1) S = M;
                else E = M-1;
            }
            done = S;
            P = T;
        }
        if(done >= n) pr.println("YES");
        else pr.println("NO");
    }
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
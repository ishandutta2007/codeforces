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
var k = 0L;

fun solve() {
    n = sc.nextInt();
    m = sc.nextInt();
    k = sc.nextLong();
    var a = Array(n+1) {0L};
    var s = Array(n+1) {0L};
    for(i in 1..n) {
        a[i] = sc.nextLong();
    }
    a.sort();
    for( i in 1..n) {
        s[i] = s[i-1] + a[i];
    }
    var ans = Long.MAX_VALUE;
    for( i in 1..n-m+1) {
        var S = a[i];
        var E = a[i-1+(m+1)/2];
        while(S<E) {
            var M = (S+E)/2 + 1;
            var IS = i;
            var IE = i-1+(m+1)/2;
            while(IS < IE) {
                var IM = (IS+IE)/2 + 1;
                if(a[IM] <= M) IS = IM;
                else IE = IM-1;
            }
            if((IS-i+1)*M - (s[IS]-s[i-1]) <= k) S = M;
            else E = M-1;
        }
        var IS = i;
        var IE = i-1+(m+1)/2;
        while(IS < IE) {
            var IM = (IS+IE)/2 + 1;
            if(a[IM] <= S) IS = IM;
            else IE = IM-1;
        }
        ans = min(ans, (IS-i+1)*S - (s[IS]-s[i-1]) + (s[i+m-1]-s[IS]) - (m-IS+i-1)*S);
    }
    pr.println(ans);
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
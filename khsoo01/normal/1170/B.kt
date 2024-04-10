import java.io.*
import java.util.*

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

fun solve() {
    var n = sc.nextInt();
    var a = Array(200005) {0};
    var mx1 = 0;
    var mx2 = 0;
    var cnt = 0;
    for(i in 1..n) {
        a[i] = sc.nextInt();
        if(mx2 > a[i]) cnt++;
        if(mx1 < a[i]) {
            mx2 = mx1;
            mx1 = a[i];
        }
        else if(mx2 < a[i]) {
            mx2 = a[i];
        }
    }
    pr.println(cnt);
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
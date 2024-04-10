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

const val HAVE_TO_GET_TC = true;
var TC = 1;

fun solve() {
    var a = sc.nextLong();
    var b = sc.nextLong();
    if(a > b) {
        var tmp = a;
        a = b;
        b = tmp;
    }
    pr.print(1);
    pr.print(" ");
    pr.print(a-1);
    pr.print(" ");
    pr.println(b-a+1);
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
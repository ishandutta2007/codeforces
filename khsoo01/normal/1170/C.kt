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
    val str1 = sc.next();
    val str2 = sc.next();
    if(str2.length > str1.length) { pr.println("NO");return; }
    var done = 0;
    for(i in 0 until str2.length) {
        if(done >= str1.length)  { pr.println("NO");return; }
        if(str2[i] == '-') {
            if (str1[done] == '+') { pr.println("NO");return; }
            else done++;
        }
        else {
            if(str1[done] == '-') {
                if(done+1 >= str1.length || str1[done+1] != '-')  { pr.println("NO");return; }
                done += 2;
            }
            else done++;
        }
    }
    if(done < str1.length)  { pr.println("NO");return; }
    pr.println("YES");
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
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

class disjoint_set {
    var par = Array(300005) {0}
    init {
        for(i in 0 until 300005) {
            par[i] = i;
        }
    }
    fun find (x : Int) :Int {
        if(par[x] == x) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    fun use (x : Int) {
        par[x] = x+1;
    }
}

var a = Array(300005) {0};
var ans = Array<ArrayList<Int>>(300005){ArrayList<Int>(0)};
var dis = disjoint_set();

fun solve() {
    m = sc.nextInt();
    for(i in 0 until m) {
        a[i] = sc.nextInt();
        if(a[i] == -1) n++;
    }
    var i = 0;
    while(i < m) {
        var j = -1;
        while(true) {
            j = dis.find(j+1);
            if(j >= n) break;
            if(a[i] == -1) dis.use(j);
            else ans[j].add(a[i]);
            i++;
        }
    }
    pr.println(n);
    for(i in 0 until n) {
        pr.print(ans[i].size);
        for(j in 0 until ans[i].size) {
            pr.print(" ");
            pr.print(ans[i][j]);
        }
        pr.println();
    }
}

fun main (args: Array<String>) {
    if(HAVE_TO_GET_TC) TC = sc.nextInt();
    for(i in 1..TC) {
        solve();
    }
    pr.flush();
}
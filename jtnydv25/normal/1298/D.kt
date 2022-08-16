import java.lang.Long.max
import java.lang.Long.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val (n, w) = readInts();
    var prefix = 0L;
    val a = readInts();
    var mn = Long.MAX_VALUE;
    var mx = Long.MIN_VALUE;
    for(i in 0..n-1){
        prefix += a[i];
        mn = min(prefix, mn);
        mx = max(prefix, mx);
    }
    // s + mn >= 0, s + mx <= w
    println(max(0L, min(w.toLong(), w - mx) - max(0L, -mn) + 1));
}
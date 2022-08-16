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
    val (n, k) = readInts();
    var r = readLongs();
    var P = ArrayList<Long>();
    for(i in 0..n-1){
        P.add((r[i] shl 20) + i);
    }
    P.sort();

    var ans = IntArray(n);

    var now = -1L;
    var cnt = 0;
    for(i in 0..n-1){
        val u = P.get(i).and((1 shl 20) - 1);
        val v = P.get(i) shr 20;
        if(v != now) cnt = i;
        now = v;
        ans[u.toInt()] = cnt;
    }

    for(i in 0..k-1){
        var (u, v) = readInts();
        u--; v--;
        if(r[u] > r[v]){
            ans[u]--;
        } else if(r[v] > r[u])ans[v]--;
    }
    for(i in 0..n-1){
        print("${ans[i]} ");
    }
}
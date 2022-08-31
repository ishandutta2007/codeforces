import FenwickTree.add
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

object FenwickTree {

    // T[pos] += value
    fun add(t: IntArray, pos: Int, value: Int) {
        var i = pos
        while (i < t.size) {
            t[i] += value
            i = i or i + 1
        }
    }

    // sum[0..pos]
    fun sum(t: IntArray, pos: Int): Int {
        var res = 0
        var i = pos
        while (i >= 0) {
            res += t[i]
            i = (i and i + 1) - 1
        }
        return res
    }

    ///////////////////////////////////////////////////

    // T[pos] = max(T[pos], value)
    fun set(t: IntArray, pos: Int, value: Int) {
        var i = pos
        while (i < t.size) {
            t[i] = maxOf(t[i], value)
            i = i or i + 1
        }
    }

    // max[0..pos]
    fun max(t: IntArray, pos: Int): Int {
        var i = pos
        var res = Int.MIN_VALUE
        while (i >= 0) {
            res = maxOf(res, t[i])
            i = (i and i + 1) - 1
        }
        return res
    }
}


fun main(){
    val (n, m) = readInts()
    val p = readInts()
    fun get( a: IntArray) : Long{
        var arr = IntArray(2 * n + 10)
        var prefix = n + 5
        var ret = 0L;
        add(arr, prefix, 1);
        for(i in 0..n-1){
            prefix += a[i];
            ret += FenwickTree.sum(arr, prefix - 1);
            add(arr, prefix, 1);
        }
        return ret
    }
    var a = IntArray(n) {if(p[it] >= m) 1 else -1}
    var b = IntArray(n) {if (p[it] > m) 1 else -1}
    println(get(a) - get(b))
}
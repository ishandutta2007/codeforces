import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main() {
    val t = readInt()
    for(i in 0 until t){
        var (n, x, y) = readInts()
        if(x > y) x = y.also { y = x }
        val left = x - 1
        val right = n - y
        val middle = y - x
        var lo = maxOf(left, right)
        var hi = lo + middle

        fun getMax(a: Int, k: Int) : Int{
            if(k <= 3 * a) return (k - a) / 2
            return k - 2 * a
        }
        while(lo < hi){
            val k = (lo + hi) / 2
            if(getMax(left, k) + getMax(right, k) >= middle-1) hi = k
            else lo = k + 1
        }
        println(lo)
    }
}
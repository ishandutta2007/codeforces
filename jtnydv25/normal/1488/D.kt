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
    repeat(readInt()) {
        val (n, s) = readLongs()
        var lo = 1L
        var hi = s
        while(lo < hi){
            var mid = (lo + hi + 1) / 2
            var sum = 0L
            var k = 0L
            var x = mid
            for(i in 0..minOf(n-1, 64)){
                k += 1
                sum += x
                x = (x + 1) / 2
            }
            sum += n - k
            if(sum <= s) lo = mid
            else hi = mid - 1
        }
        println(lo)
    }

}
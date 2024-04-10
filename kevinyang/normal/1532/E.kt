import kotlin.system.exitProcess
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
    var n = readInt()
    var a = readInts()
    var prefMax = IntArray(n + 1)
    var prefSum = LongArray(n + 1)
    var sufMax = IntArray(n + 1)
    var sufSum = LongArray(n + 1)
    for (i in 0 until n) {
        prefMax[i + 1] = maxOf(prefMax[i], a[i])
        prefSum[i + 1] = prefSum[i] + a[i]
    }
    for (i in n - 1 downTo 0) {
        sufMax[i] = maxOf(sufMax[i + 1], a[i])
        sufSum[i] = sufSum[i + 1] + a[i]
    }
    var nice = ArrayList<Int>()
    for (i in 0 until n) {
        var max = maxOf(prefMax[i], sufMax[i + 1])
        var sum = prefSum[i] + sufSum[i + 1]
        if (2L * max == sum) {
            nice.add(i + 1)
        }
    }
    println(nice.size)
    println(nice.joinToString(" "))
}
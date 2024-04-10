fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach() {
        print("$it ")
    }
    println()
}

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    for (i in 0 until n - 2) {
        if (a[i] == a[i + 2]) {
            println("NO")
            return
        }
    }
    val inc: MutableList<Int> = mutableListOf(a[0])
    val dec: MutableList<Int> = mutableListOf()
    for (i in 1 until n) {
        if (a[i] != a[i - 1])
            inc.add(a[i])
        else
            dec.add(a[i])
    }
    dec.reverse()
    println("YES")
    println(inc.size)
    printInts(inc)
    println(dec.size)
    printInts(dec)
}
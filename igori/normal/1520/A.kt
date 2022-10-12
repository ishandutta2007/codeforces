fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach {
        print("${it + 1} ")
    }
    println()
}

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val s = readLine()!!
        var tr = true
        s.forEach { c ->
            val t = s.substring(s.indexOf(c), s.lastIndexOf(c))
            if (t.minOrNull() != t.maxOrNull())
                tr = false
        }
        if (tr) {
            println("YES")
        } else {
            println("NO")
        }
    }
}
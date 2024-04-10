fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun printInts(list: List<Int>) {
    list.forEach {
        print("${it + 1} ")
    }
    println()
}

fun main() {
    val (n, k) = readInts()
    var s = readLine()!!

    val l = mutableListOf<MutableList<Int>>()
    while (true) {
        val e = mutableListOf<Int>()
        var i = 0
        val t = StringBuilder()
        while (true) {
            val p = s.findAnyOf(listOf("RL"), i) ?: break
            t.append(s.substring(i, p.first))
            t.append("LR")
            e.add(p.first)
            i = p.first + 2
        }
        if (i < s.length)
            t.append(s.substring(i, s.length))
        if (e.isNotEmpty()) {
            l.add(e)
        } else {
            break
        }
        s = t.toString()
    }
    if (k < l.size || k > l.flatten().size) {
        println(-1)
        return
    }
    var cnt = k - l.size
    val out = StringBuilder()
    l.forEach {
        repeat(it.size) { i ->
            if (i + 1 == it.size) {
                out.append("1 ${it[i] + 1} ")
            } else if (cnt > 0) {
                out.append("1 ${it[i] + 1} ")
                cnt--
            } else {
                out.append("${it.size - i} ")
                it.subList(i, it.size).forEach { x ->
                    out.append("${x + 1} ")
                }
                return@forEach
            }
        }
    }
    println(out)
}
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!.split(" ").map { it.toInt() }.sum() - n
        println(when {
            s < 0 -> 1
            else -> s
        })
    }
}
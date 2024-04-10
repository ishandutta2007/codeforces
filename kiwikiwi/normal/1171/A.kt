fun nextInt() = readLine()!!.toInt()

fun main(args: Array<String>) {
    val T = nextInt()
    repeat(T) {
        val x = nextInt()
        println(x / 2)
    }
}
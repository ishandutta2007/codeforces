fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var T = nextInt()
    repeat(T) {
        var s = nextLn().toCharArray()
        s.sort()
        if (s[0] == s[s.size - 1])
            println(-1)
        else
            println(s)
    }
}
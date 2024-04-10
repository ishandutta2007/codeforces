fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }

fun main(args: Array<String>) {
    var (n, x, y) = nextInts()
    var s = nextLn()
    var ans = 0
    for (i in n - x .. n - 1) {
        if (i == n - y - 1) {
            if (s[i] != '1') ans += 1
        } else {
            if (s[i] != '0') ans += 1
        }
    }
    println(ans)
}
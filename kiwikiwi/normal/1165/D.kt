fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }
fun nextLongs() = nextStrings().map { it.toLong() }


fun main(args: Array<String>) {
    var T = nextInt()
    repeat(T) {
        var n = nextInt()
        var d = nextLongs()
        d = d.sorted()
        var x = d[0] * d[d.size - 1]
        var newd = ArrayList<Long>()
        for (i : Long in 2 .. x - 1) {
            if (i * i > x) {
                break
            }
            if (x % i == 0L) {
                newd.add(i)
                if (i * i != x) {
                    newd.add(x / i)
                }
            }
        }
        newd.sort()
        if (d.size != newd.size) {
            x = -1
        } else {
            for (i in 0 .. d.size - 1)
                if (d[i] != newd[i]) {
                    x = -1
                }
        }
        println(x)
    }
}
fun nextLn() = readLine()!!
fun nextInt() = nextLn().toInt()
fun nextStrings() = nextLn().split(" ")
fun nextInts() = nextStrings().map { it.toInt() }
fun nextLongs() = nextStrings().map { it.toLong() }

var mod = 998244353

fun main(args: Array<String>) {
    var (n, m) = nextInts()
    var a = MutableList<ArrayList<Int>>(456789) {ArrayList<Int>()}
    var cntk = nextInts().toMutableList()
    for (i in 1 .. m) {
        var (d, t) =nextInts()
        a[d].add(t - 1)
    }
    fun check(d : Int) : Boolean {
        var money = 0
        var cnt = cntk.toMutableList()
        var lastd = MutableList<Int>(n) {d + 1}
        for (i in 1 .. d) {
            for (k in a[i]) {
                lastd[k] = i
            }
        }
        for (i in 1 .. d) {
            money += 1
            for (k in a[i]) {
                if (lastd[k] != i)
                    continue
                var c = minOf(cnt[k], money)
                cnt[k] -= c
                money -= c
            }
        }
        for (i in 0 .. n-1) {
            money -= 2 * cnt[i]
        }
        return money >= 0
    }
    var l = 0
    var r = 400001
    while (l + 1 < r) {
        var mid = (l + r) / 2
        if (check(mid)) 
            r = mid
        else
            l = mid
    }
    println(r)
}
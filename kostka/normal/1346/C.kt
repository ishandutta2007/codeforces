fun main(args: Array<String>) {
  val t = readLine()!!.toInt()
  for(ti in 1..t) {
    val (n, k, x, y) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).toMutableList()
    a.add(0)
    a.sortDescending()
    var sum : Long = 0
    for(i in 0..n-1) {
      sum += a[i]
    }
    var res = n*x+y
    for(i in 0..n) {
      if (k >= (sum+n-1)/n) {
        if (a[i] <= k) {
          res = minOf(i*x, res)
        } else {
          res = minOf(i*x+y, res)
        }
      }
      sum -= a[i]
    }
    println(res)
  }
}
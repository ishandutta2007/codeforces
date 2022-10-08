fun main(args: Array<String>) {
  val t = readLine()!!.toInt()
  for(i in 1..t) {
    var (n, k) = readLine()!!.split(' ').map(String::toInt)
    var n1 = n / (1+k+k*k+k*k*k)
    print(n1)
    print(" ")
    print(n1*k)
    print(" ")
    print(n1*k*k)
    print(" ")
    print(n1*k*k*k)
    print("\n")
  }
}
fun main(args: Array<String>) {
  var (a, b) = readLine()!!.split(' ').map(String::toInt)
  var counter = 0
  while(a <= b) {
      a *= 3
      b *= 2
      counter++
  }
  println(counter)
}
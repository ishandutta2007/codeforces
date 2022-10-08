fun main(args: Array<String>) {
  val (_, nb) = readLine()!!.split(' ').map(String::toInt)
  val (ma, mb) = readLine()!!.split(' ').map(String::toInt)
  val A = readLine()!!.split(' ').map(String::toInt)
  val B = readLine()!!.split(' ').map(String::toInt)
  if(A[ma-1] < B[nb-mb]) println("YES")
  else println("NO")
}
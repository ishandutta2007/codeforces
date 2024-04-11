import kotlin.math.max

fun score(p: Int, c: Int, x: Int) : Int {
  return max(0, p-c*x)
}

fun main(args: Array<String>) {
  val (n, c) = readLine()!!.split(" ").map(String::toInt)
  val p = readLine()!!.split(" ").map(String::toInt)
  val t = readLine()!!.split(" ").map(String::toInt)
  var (score_limak, score_radewoosh) = listOf(0, 0)
  var (time_limak, time_radewoosh) = listOf(0, 0)
  for(i in 0..n-1) {
    time_limak += t[i]
    score_limak += score(p[i], c, time_limak)
  }
  for(i in n-1 downTo 0) {
    time_radewoosh += t[i]
    score_radewoosh += score(p[i], c, time_radewoosh)
  }
  if(score_radewoosh == score_limak) println("Tie")
  else if(score_radewoosh > score_limak) println("Radewoosh")
  else println("Limak")
}
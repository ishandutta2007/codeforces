import kotlin.math.*
import java.util.*
import java.math.*

fun main(args : Array<String>) = with(Scanner(System.`in`)) {
	var n = nextInt()
	var cnt1 = 0
	var cnt2 = 0
	for (i in 1..n){
		var s = next()
		var t = next()
		if(t == "soft") cnt1++
		else cnt2++
	}
	if(cnt1 > cnt2){
		cnt1 = cnt2.also{
			cnt2 = cnt1
		}
	}
	for(i in 1..100){
		if((i * i) / 2 >= cnt1 && (i*i+1) / 2 >= cnt2){
			println(i)
			return
		}
	}
}
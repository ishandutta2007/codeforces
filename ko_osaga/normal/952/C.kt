import kotlin.math.*
import java.util.*
import java.math.*

fun main(args : Array<String>) = with(Scanner(System.`in`)) {
	var n = nextInt()
	var arr = Array(n) { nextInt() } 
	for (i in n downTo 1){
		for (j in 1..(i-1)){
			if(abs(arr[j] - arr[j-1]) >= 2){
				println("NO")
				return
			}
		}
		var pos = 0
		for (j in 1..(i-1)){
			if(arr[j] > arr[pos]) pos = j
		}
		for (j in pos..(i-2)){
			arr[j] = arr[j+1]
		}
	}
	println("YES")
}
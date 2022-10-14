import java.util.ArrayList


fun main()
{

    /*var n=readLine()!!.split((' ')).map(String::toLong)
    var b=n[0];var k=n[1]
    var cnt:Long=0;var ans:Long=0
    class pair(x:Long,y:Long){}
    val mp=ArrayList<Pair<Long,Long> >()
    for(i in 1..b)
    {
        var array=readLine()!!.split(' ').map(String::toLong)
        cnt+=array[0]
        ans+=array[0]*array[2]
        mp.add(array[2]to array[1]-array[0])
    }

    mp.sortBy { it.first }
    var i=0
    while(cnt<k&&i<b)
    {
        if(cnt+mp[i].second<k){cnt+=mp[i].second;ans+=mp[i].first*mp[i].second}
        else if(cnt+mp[i].second>=k){ans+=mp[i].first*(k-cnt);cnt+=k-cnt}
        i++;
        //print(""+cnt+"\n")
    }
if(cnt!=k)print(-1)
    else print(ans)
*/
    var n=readLine()!!.split((' ')).map(String::toInt)
    var i=0
    while(i<n[0])
    {
        var x=readLine()!!.split((' ')).map(String::toInt)
        var y=x[0]
        if(y<4) print("-1\n")
        else {
            var ar = ArrayList<Int>()
            var chk = 0
            var num = 0
            while (num + 3 < y) {
                chk = num / 4
                if (chk % 2 == 0) {
                    ar.add(num + 3);ar.add(num + 1);ar.add(num + 4);ar.add(num + 2)
                } else {
                    ar.add(num + 2);ar.add(num + 4);ar.add(num + 1);ar.add(num + 3)
                }

                num += 4
            }
            if (y % 4 == 1) ar.add(y)
            else if (y % 4 != 0) {
                var old = y
                if (y % 4 == 3) y--;
                chk = num / 4
                if (chk % 2 == 0) {

                    ar.add(y);ar.add(y - 1);
                    ar[y - 5] = ar[y - 1].also { ar[y - 1] = ar[y - 5] }
                } else {
                    ar.add(y);ar.add(y - 1);
                    ar[y - 4] = ar[y - 1].also { ar[y - 1] = ar[y - 4] }

                }
                y = old
                if (y % 4 == 3) {
                    ar.add(y)
                }

            }
            for (i in 0..ar.size - 1) print("" + ar[i] + " ")
            print("\n")
        }
        i++


    }

//3 1 4 2 6 8 5 7 10 9

}
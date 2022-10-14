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
        var ar=readLine()!!.split((' ')).map(String::toInt)
        var y=x[0]
        var right=y-1
        var rt=0
        var lft=0
        var al=0
        var bob=0
        var cnt=0
        var ind=0
        while(ind<=right)
        {
            lft+=ar[ind]
            al+=ar[ind]
            if(ind==right){cnt++;break}
            if(lft>rt) {
                var used=false
                rt=0
                cnt++
                while(right>ind&&rt<=lft)
                {
                    rt+=ar[right]
                    bob+=ar[right]
                    right--
                    used=true
                }
                if(used)cnt++
                lft=0
            }
            ind++
        }
        i++
print(""+cnt+" "+al+" "+bob+"\n")
    }
}
def sol(n):
    cnt=3
    if n==180:
        return -1
    while True:
        if cnt>10000000:
            break
         
        ma=((180)*(cnt-2))/cnt
        if n>ma:
            cnt+=1 
            continue
        if (n*cnt)%(180)==0:
            return cnt
        cnt+=1
        
    return -1
dp=[0 for i in xrange(190)]
for i in xrange(180):
    dp[i+1]=sol(i+1)
for t in xrange(input()):
    print dp[input()]
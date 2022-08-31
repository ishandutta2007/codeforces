n=input()
mod=998244353



def fexpo(a,p):
    x=a 
    cnt=p 
    ans=1
    while cnt:
        if (cnt%2==1):
            ans=(ans*x)%mod 
        x=(x*x)%mod 
        cnt/=2 
    return ans 

    

bit=[0 for i in xrange(n+1)]
def gets(ind):
    s=0
    while (ind>0) :
        s+= bit[ind]; 
        ind-= ind&(-ind)
    return s 
arr=map(int,raw_input().split())
    
def updateBIT( n, index,val) :
    while (index <= n):
       bit[index] += val
       index += index & (-index)
ans=0
for i in xrange(n-1,-1,-1):
    if arr[i]!=-1:
        ans+=gets(arr[i])
        updateBIT(n,arr[i],1)

#print ans
totcnt=0
p=0
q=1
#bit=[0 for i in xrange(n+1)]
for i in xrange(n-1,-1,-1):
    if arr[i]==-1:
        totcnt+=1 
cnt=0
for i in xrange(n-1,-1,-1):
    if arr[i]!=-1:
        u=gets(arr[i])
        rem=arr[i]-u 
        #print rem,cnt,totcnt
        #print fexpo(totcnt,mod-1)
        tmp=(rem*cnt)%mod 
        #print tmp
        tmp=(tmp*fexpo(totcnt,mod-2))%mod
        #print tmp
        rem=(totcnt-rem)
        tmp2=(rem*(totcnt-cnt))%mod 
        #print rem,totcnt-cnt
        tmp2=(tmp2*fexpo(totcnt,mod-2))
        #print tmp2
        ans=(ans+tmp+tmp2)%mod 
    else:
        cnt+=1 

tmp=(totcnt*(totcnt-1))%mod 
tmp=(tmp*fexpo(4,mod-2))%mod 
ans=(ans+tmp)%mod

print ans
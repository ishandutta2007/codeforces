n=input()
l=map(int,raw_input().split())
s=sum(l)

def val(a,b):
    return max(b-a,0)
if s%n==0:
    ans=0
    mini=s//n
    for i in l:
        ans+=val(i,mini)
    print ans 
else:
    mini=s//n 
    maxi=mini+1 
    reqi=n-(s%n)
    ans=0
    cnt=0
    for i in l:
        if cnt<reqi:
            if i<=mini:
                ans+=mini-i
                cnt+=1 
        else:
            ans+=val(i,maxi)
    print ans
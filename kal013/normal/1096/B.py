mod=998244353
n=input()
s=raw_input().strip()

cntl=1
cntr=1 
while cntl<n:
    if s[cntl]==s[cntl-1]:
        cntl+=1 
    else:
        break
while cntr<n:
    if s[(n-cntr)]==s[(n-1-cntr)]:
        cntr+=1 
    else:
        break
assert(cntl!=n)
ans=(cntl+cntr+1)%mod
if (s[0]==s[n-1]):
    ans=(ans+(cntl)*(cntr)%mod)%mod 
print ans
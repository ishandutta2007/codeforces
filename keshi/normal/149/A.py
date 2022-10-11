k=int(input())
f=0
a=sorted(map(int,input().split()))
a.reverse()
i=0
while f<k and i<12:
    f+=a[i]
    i+=1
if f<k:
    i=-1
print(i)
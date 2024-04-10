k,r=map(int,input().split())
k=k%10
f=k
i=1
while k!=r and k:
    k=(k+f)%10
    i+=1
print(i)
n=int(input())
s=n
n-=1
i=1
while n:
    s+=n*i
    i+=1
    n-=1
print(s)
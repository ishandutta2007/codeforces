n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=list(map(int,input().split()))
a.sort()
f=0
for i in a:
    if i-1 in b:
        b.remove(i-1)
        f+=1
    elif i in b:
        b.remove(i)
        f+=1 
    elif i+1 in b:
        b.remove(i+1)
        f+=1
print(f)
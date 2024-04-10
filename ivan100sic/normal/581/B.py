input()
a=list(map(int, input().split()))[::-1]
x=-1
b=[]
for v in a:
 b+=[max(0,x-v+1)]
 x=max(x,v)
print(*b[::-1])
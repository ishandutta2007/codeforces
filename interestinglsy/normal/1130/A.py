n = int(input())
a = list(map(int,input().split()))
shouldbe = (n+1)//2
po,ne = 0,0
for i in a:
    if i > 0: po += 1
    if i < 0: ne += 1
if po >= shouldbe: print(1)
elif ne >= shouldbe: print(-1)
else: print(0)
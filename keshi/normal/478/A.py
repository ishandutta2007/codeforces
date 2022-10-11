s=sum(map(int,input().split()))
if s%5 or not s:
    print(-1)
else:
    print(s//5)
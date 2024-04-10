n = int(input())
l = list(map(int, input().split()))
s = sum(l)
print(max((s*2+n)//n,max(l)))
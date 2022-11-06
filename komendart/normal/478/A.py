s = sum(int(i) for i in input().split())

if s > 0 and s % 5 == 0:
    print(s // 5)
else:
    print(-1)
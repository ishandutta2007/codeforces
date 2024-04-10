a = sum(map(int, input().split()))
print(-1 if not a or a % 5 else a // 5)
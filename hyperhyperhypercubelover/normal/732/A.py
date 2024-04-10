n, m = map(int, input().split())
for i in range(1, 100):
  if not n * i % 10 or n * i % 10 == m:
    print(i)
    exit(0)
n, k = map(int, input().split())
print(n - len(''.join('x '[int(v) <= k] for v in input().split()).strip()))
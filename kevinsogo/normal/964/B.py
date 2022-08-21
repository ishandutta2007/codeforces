n, a, b, c, t = map(int, raw_input().split())
print sum(a + max(0, (t - x) * (c - b)) for x in map(int, raw_input().split()))
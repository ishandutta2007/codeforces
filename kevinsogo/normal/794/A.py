a, b, c = map(int, raw_input().strip().split())
input()
v = map(int, raw_input().strip().split())
print sum(b < x < c for x in v)
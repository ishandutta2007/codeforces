n = int(input())
r = 0
for _ in range(n):
  a, b = map(int, input().split())
  if a < b:
    r -= 1
  if a > b:
    r += 1
print('Mishka' if r > 0 else 'Chris' if r < 0 else 'Friendship is magic!^^')
def li():
  return list(map(int, input().split(" ")))
a = sorted(li());
print(a[3]-a[0], a[3]-a[1], a[3]-a[2])
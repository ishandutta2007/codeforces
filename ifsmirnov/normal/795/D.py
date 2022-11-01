n, l, r = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a[l-1:r] = sorted(a[l-1:r])
b[l-1:r] = sorted(b[l-1:r])
if a == b:
    print("TRUTH")
else:
    print("LIE")
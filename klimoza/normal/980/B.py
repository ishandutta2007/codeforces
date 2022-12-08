n, k = map(int, input().split())
print("YES")
if(k % 2 == 0):
    print("." * n)
    print("." + "#" * (k // 2) + "." * (n - 1 - k // 2))
    print("." + "#" * (k // 2) + "." * (n - 1 - k // 2))
    print("." * n)
else:
    if(k <= n - 2):
        t = (n - k) // 2
        print("." * n)
        print("." * t + "#" * k + "." * t)
        print("." * n)
        print("." * n)
    else:
        t = k - (n - 2)
        print("." * n)
        print("." + "#" * (n - 2) + ".")
        print("." * (n // 2 - t // 2) + "#" * (t // 2) + "." + "#" * (t // 2) + "." * (n // 2 - t // 2))
        print("." * n)
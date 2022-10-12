def main():
    n, H = map(int, input().split())
    m = n
    n += H * (H - 1) / 2
    l = H
    r = 2000000000000000000
    while l + 1 < r :
        mid = (l + r) // 2
        heap = mid // 2
        kek = 0
        if mid % 2 == 1 :
            kek += heap * (heap +  1)
            kek += heap + 1
        else :
            kek += heap * (heap + 1)
        if kek >= n:
            r = mid
        else :
            l = mid
    a = 0
    b = H
    while a + 1 < b :
        mid = (a + b) // 2
        kek = mid * (mid + 1) // 2
        if kek >= m :
            b = mid
        else :
            a = mid
    if H * (H + 1) // 2 >= m :
        print(b)
        exit()
    print(r - H + 1)
main()
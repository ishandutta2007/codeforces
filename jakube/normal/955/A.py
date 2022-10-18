hh, mm = [int(x) for x in input().split()]
H, D, C, N = [int(x) for x in input().split()]

res = (H + N - 1) // N * (C if hh < 20 else C * 0.8)
if hh < 20:
    minutes = (20 - hh) * 60 - mm
    x = H + minutes * D
    res = min(res, (x + N - 1) // N * (C * 0.8))
print("{:.8f}".format(float(res)))
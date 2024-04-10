s, v1, v2, t1, t2 = map(int, input().split())
h1 = v1 * s + 2 * t1
h2 = v2 * s + 2 * t2
if h1 < h2:
    print("First")
elif h2 < h1:
    print("Second")
else:
    print("Friendship")
a=input()
print(max(int(a),int(a[:-1]),int(a[:-2]+a[-1])))